# Write your MySQL query statement below
-- using self join
SELECT DISTINCT a.email 
from person a join person b
on (a.email=b.email)
where a.id<>b.id;