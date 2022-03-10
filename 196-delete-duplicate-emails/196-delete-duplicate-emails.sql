# Write your MySQL query statement below
DELETE p
FROM person p, person q
where p.email = q.email and p.id>q.id;