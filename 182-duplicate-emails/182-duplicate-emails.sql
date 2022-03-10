# Write your MySQL query statement below
SELECT DISTINCT a.email 
from person a join person b
on (a.email=b.email)
where a.id<>b.id;