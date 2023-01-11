import networkx as nx
import matplotlib.pyplot as plt
import pandas as pd

# Method chuyển đổi tên thông thường thành tên rút gọn
# VD: PHẠM VĂN LINH => P.V.LINH
def shortenName(name):
    args = name.split()
    if len(args) == 1:
        return name
    shortName = ""
    for i in range(len(args) - 1):
        shortName += args[i][0] + "."
    shortName += args[-1]
    return shortName

# Nhập đường dẫn đến file dữ liệu (Excel)
inputFilePath = input("Nhập đường dẫn đến file dữ liệu:\n")
data = pd.read_excel(inputFilePath)

print("Đang xử lí ...")

# Đọc các tên từ cột Name từ file dữ liệu và
# chuyển đổi thành các tên rút gọn
displayNames = []
for name in data["Name"]:
    displayNames.append(shortenName(name))

# Đọc tên của đối tác mà từng người muốn làm
# việc cùng vào, dưới dạng tên rút gọn
linkoutData = []
for name,linkoutList in zip(displayNames, data["Link out"]):
    if type(linkoutList) == str:
        args = linkoutList.split(", ")
        parsedNames = [shortenName(i) for i in args]
        linkoutData.extend([(name, target) for target in parsedNames])

# Khởi tạo đồ thị và load tên từng người và
# đối tác của họ vào đồ thị
graph = nx.DiGraph()
graph.add_nodes_from(displayNames)
graph.add_edges_from(linkoutData)

# Thiết lập màu và kích cỡ từng nodes
nodeColors = [item[1] for item in graph.in_degree(graph.nodes)] # Thiết lập màu dựa vào số lượng người muốn làm việc cùng
nodeSize = [item*(500000/2) for item in list(nx.pagerank(graph).values())] # Thiết lập kích cỡ bằng phương pháp PageRank

# Thiết lập kích cỡ và tiêu đề đồ thị
plt.figure(figsize=(20, 20))
plt.title("Computer Science 64 Social Network")
pos = nx.spring_layout(graph, k=1.8)

# Thiết lập khoảng cho thanh chỉ thị màu
vmin = min(nodeColors)
vmax = max(nodeColors)

# Vẽ các thành phần của đồ thị lên màn hình đồ họa
nodeDraw = nx.draw_networkx_nodes(graph, pos, graph.nodes, node_color=nodeColors, cmap="Pastel1",
                                  vmin=vmin, vmax=vmax, label=True, node_size=nodeSize)
edgeDraw = nx.draw_networkx_edges(graph, pos, node_size=nodeSize, edge_color="gray", arrowstyle="-|>")
labelDraw = nx.draw_networkx_labels(graph, pos, font_size=12, font_color="black")

# Vẽ thanh chỉ thị màu
plt.colorbar(nodeDraw)

# Xuất file thành phẩm ra
plt.savefig("output.png")
print("Đã xuất thành file output.png.")

