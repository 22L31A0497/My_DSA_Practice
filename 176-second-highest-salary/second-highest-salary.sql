# Write your MySQL query statement below
# Write your MySQL query statement below
select(
select DISTINCT e.salary  
from Employee  e
order by e.salary desc
LIMIT 1 OFFSET 1

) as SecondHighestSalary;