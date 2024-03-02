-- Câu 1
ALTER TABLE SOTK ADD TinhTrang char(1)

-- Câu 2
UPDATE SOTK SET MaLTK = 'VND3' WHERE MaSo = 'S230'

-- Câu 3
INSERT INTO DMKH VALUES ('KH6', 'Phạm Văn Linh', '11223735', 'Ninh Bình', '0787097309')

-- Câu 4
SELECT * FROM (DMKH INNER JOIN SOTK ON DMKH.MaKH = SOTK.MaKH) WHERE NgayGui = '1/6/2019' 

-- Câu 5
SELECT * FROM (SELECT *, COUNT(MaSo) AS SOLUONG FROM SOTK GROUP BY MAKH) WHERE SOLUONG >= 3

-- Câu 6
SELECT * FROM SOTK WHERE SoTien > 20000 AND MALTK LIKE "USD%"

-- Câu 7
SELECT COUNT(*) FROM SOTK WHERE MONTH(NgayGui) = 6 AND YEAR(NgayGui) = 2019

-- Câu 8
SELECT * FROM SOTK WHERE MaKH = 'KH3' AND YEAR(NgayRut) = 2020

-- Câu 9
SELECT MaSo, SoTien FROM SOTK WHERE SoTien = MAX(SoTien)

-- Câu 10
SELECT SUM(SoTien) FROM SOTK WHERE YEAR(NgayGui) = 2019