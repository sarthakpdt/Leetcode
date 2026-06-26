# Write your MySQL query statement below
select Employee.name as Employee from Employee join Employee mrg on Employee.managerId=mrg.id and Employee.salary>mrg.salary