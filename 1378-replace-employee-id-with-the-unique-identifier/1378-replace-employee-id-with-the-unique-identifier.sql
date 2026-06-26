# Write your MySQL query statement below
select euni.unique_id, e.name from Employees e
left join EmployeeUNI euni
ON euni.id = e.id;