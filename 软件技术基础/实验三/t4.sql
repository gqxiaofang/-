/****** Script for SelectTopNRows command from SSMS  ******/
SELECT  SUM(S.OrderQty*(S.UnitPrice-P.StandardCost)) AS Profit
  FROM [AdventureWorksLT2008].[SalesLT].[SalesOrderDetail] S,
  [AdventureWorksLT2008].[SalesLT].Product P
  WHERE S.ProductID = P.ProductID AND P.Name = 'Mountain-200 Silver, 42'