SELECT COUNT(*) AS MountainBikesCount
  FROM [AdventureWorksLT2008].[SalesLT].[Product] A, 
  [AdventureWorksLT2008].[SalesLT].[ProductCategory] B
  WHERE A.ProductCategoryID = B.ProductCategoryID 
  AND B.Name = 'Mountain Bikes';

SELECT *
  FROM [AdventureWorksLT2008].[SalesLT].[Product] A, 
  [AdventureWorksLT2008].[SalesLT].[ProductCategory] B
  WHERE A.ProductCategoryID = B.ProductCategoryID 
  AND B.Name = 'Mountain Bikes';
  

