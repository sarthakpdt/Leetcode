# Write your MySQL query statement below
select name from SalesPerson where sales_id not in (select Orders.sales_id from Orders,Company where Orders.com_id=Company.com_id and Company.name='RED') 