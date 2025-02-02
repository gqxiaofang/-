/****** Script for SelectTopNRows command from SSMS  ******/
SELECT DISTINCT P.Name,C.OrderQty
  FROM [AdventureWorksLT2008].[SalesLT].SalesOrderHeader A, [AdventureWorksLT2008].[SalesLT].Customer B,
  [AdventureWorksLT2008].[SalesLT].SalesOrderDetail C, [AdventureWorksLT2008].[SalesLT].Product P,
  [AdventureWorksLT2008].[SalesLT].Address AD
  WHERE B.Title = 'Mr.' AND B.FirstName = 'Jeffrey' AND B.LastName = 'Kurtz' 
  AND B.CustomerID = A.CustomerID 
  AND A.SalesOrderID = C.SalesOrderID
  AND C.ProductID = P.ProductID
  AND A.ShipToAddressID = AD.AddressID;
SELECT DISTINCT AD.AddressLine1,AD.AddressLine2,AD.City,AD.StateProvince,AD.CountryRegion,AD.PostalCode
  FROM [AdventureWorksLT2008].[SalesLT].SalesOrderHeader A, [AdventureWorksLT2008].[SalesLT].Customer B,
  [AdventureWorksLT2008].[SalesLT].SalesOrderDetail C, [AdventureWorksLT2008].[SalesLT].Product P,
  [AdventureWorksLT2008].[SalesLT].Address AD
  WHERE B.Title = 'Mr.' AND B.FirstName = 'Jeffrey' AND B.LastName = 'Kurtz' 
  AND B.CustomerID = A.CustomerID 
  AND A.SalesOrderID = C.SalesOrderID
  AND C.ProductID = P.ProductID
  AND A.ShipToAddressID = AD.AddressID;
SELECT DISTINCT A.TotalDue
  FROM [AdventureWorksLT2008].[SalesLT].SalesOrderHeader A, [AdventureWorksLT2008].[SalesLT].Customer B,
  [AdventureWorksLT2008].[SalesLT].SalesOrderDetail C, [AdventureWorksLT2008].[SalesLT].Product P,
  [AdventureWorksLT2008].[SalesLT].Address AD
  WHERE B.Title = 'Mr.' AND B.FirstName = 'Jeffrey' AND B.LastName = 'Kurtz' 
  AND B.CustomerID = A.CustomerID 
  AND A.SalesOrderID = C.SalesOrderID
  AND C.ProductID = P.ProductID
  AND A.ShipToAddressID = AD.AddressID
  