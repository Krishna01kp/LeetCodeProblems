# Write your MySQL query statement below
SELECT name as employee
FROM employee e
where salary>(
    SELECT salary from employee m where m.id= e.managerid
);