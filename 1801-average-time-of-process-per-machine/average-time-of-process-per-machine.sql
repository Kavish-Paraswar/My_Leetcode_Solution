# Write your MySQL query statement below
select m1.machine_id , ROUND((SUM(m2.timestamp - m1.timestamp)/COUNT(*)),3) As processing_time
from Activity m1,Activity m2
where m1.machine_id = m2.machine_id and 
m1.process_id = m2.process_id and 
m1.activity_type = 'start' and 
m2.activity_type = 'end' 
group by m1.machine_id