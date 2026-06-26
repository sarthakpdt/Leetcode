# Write your MySQL query statement below
select * from Cinema where Cinema.id%2!=0 and Cinema.description!='boring' order by rating DESC