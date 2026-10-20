# Write your MySQL query statement below
select e.name , b.bonus
from employee e
left join bonus b
ON e.empId = b.empId
where bonus is null or bonus < 1000