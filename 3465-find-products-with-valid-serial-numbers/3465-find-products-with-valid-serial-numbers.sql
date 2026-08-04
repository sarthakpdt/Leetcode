# Write your MySQL query statement below
select * from products where regexp_like(description,'(^| )SN[0-9]{4}-[0-9]{4}( |$)','c') order by product_id;