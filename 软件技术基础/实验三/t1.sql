/****** Script for SelectTopNRows command from SSMS  ******/
SELECT COUNT(*) AS CategoryCount
  FROM [AdventureWorksLT2008].[SalesLT].[ProductCategory]
  WHERE ParentProductCategoryID IS NULL;

SELECT A.*  FROM [SalesLT].[ProductCategory] A, SalesLT.ProductCategory B
	WHERE A.ParentProductCategoryID = B.ProductCategoryID AND
	B.ParentProductCategoryID IS NULL AND B.Name = 'Bikes'; 