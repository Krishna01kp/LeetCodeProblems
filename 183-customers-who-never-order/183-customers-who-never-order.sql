# Write your MySQL query statement below
SELECT customers.name as customers
from customers
where customers.id NOT IN (SELECT orders.customerid from orders);