# Write your MySQL query statement below
-- using left join
SELECT name as Customers from Customers
LEFT JOIN Orders
ON Customers.Id = Orders.CustomerId
WHERE Orders.CustomerId IS NULL;