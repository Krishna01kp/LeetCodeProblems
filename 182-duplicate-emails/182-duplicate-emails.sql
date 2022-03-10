# Write your MySQL query statement below
SELECT person.email
FROM person group by email
having count(email)>1;