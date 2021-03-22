2.查找入职员工时间排名倒数第三的员工的所有信息
```sql
select * from employees where hire_date=(select dinstinct hire_date from employees order by hire_date desc limit 2,1);
```
7.查找薪水涨幅超过15次的员工号emp_no以及其对应的涨幅次数t
```sql
select emp_no,count(emp_no) t from salaries groupy by emp_no having t>15;
```
8.找出所有员工当前(to_date='9999-01-01')具体的薪水salary情况，对于相同的薪水只显示一次,并按照逆序显示
```sql
select distinct(salary) t from salaries where to_data='9999-01-01' order by t desc;
```

9.获取所有部门当前manager的当前薪水情况，给出dept_no, emp_no以及salary，当前表示to_date='9999-01-01'
```sql
select de.dept_no,de.emp_no,s.salary from dept_manager de left join salaries s on de.emp_no=s.emp_no where de.to_date='9999-01-01' and s.to_date='9999-01-01';
```


10.获取所有非manager的员工emp_no

``` sql
select emp_mp from employees where employees.emp_no  not in(select emp_no from dept_manager).
```
11.获取所有员工当前的manager
``` sql
select de.emp_no,dm.emp_no manager_no from dept_emp de left join dept_manager dm on de.dept_no=dm.dept_no where de.to_date='9999-01-01' and dm.to_date='9999-01-01' and de.emp_no!=dm.emp_no
```

12.获取所有部门中当前员工薪水最高的相关信息
```sql
select dept_no,s.emp_no max(salary) salary from dept_emp de left join salaries s on de.emp_no=s.emp_no where de.to_date='9999-01-01' and s.to_date='9999-01-01' group by dept_no having s.salary=max(salary)
```
13.从titles表获取按照title进行分组
从titles表获取按照title进行分组，每组个数大于等于2，给出title以及对应的数目t。
```sql
select title,count(emp_no) from titles group by title having count(emp_no)>=2;
```
14.从titles表获取按照title进行分组，注意对于重复的emp_no进行忽略。
从titles表获取按照title进行分组，每组个数大于等于2，给出title以及对应的数目t。 注意对于重复的emp_no进行忽略。
```sql
select title,count(distinct emp_no) t from titles goupy by title having t>=2;
```
15.查找employees表所有emp_no为奇数，且last_name不为Mary的员工信息，并按照hire_date逆序排列
```sql
select * from employees where last_name!='Mary' and emp_no%2==1 order by hire_date desc;
```

16.统计出当前各个title类型对应的员工当前（to_date='9999-01-01'）薪水对应的平均工资。结果给出title以及平均工资avg。
```sql
select t.title,avg(s.salary) from titles t left join salaries s on t.emp_no=s.emp_no where s.to_date='9999-01-01' and t.to_date='9999-01-01' group by t.title;
```
17.获取当前（to_date='9999-01-01'）薪水第二多的员工的emp_no以及其对应的薪水salary
```sql
select emp_no,salary from salaries where to_date = '9999-01-01' order by salary desc limit 1,1
```
18.查找当前薪水(to_date='9999-01-01')排名第二多的员工编号emp_no、薪水salary、last_name以及first_name，不准使用order by
```sql
select e.emp_no,s.salary,e.last_name,e.first_name from employees e left join salaries s on e.emp_no=s.emp_no where 
s.salary=(select max(salary) from salaries where to_date='9999-01-01' and salary!=(select max(salary) from salaries));
```

19.查找所有员工的last_name和first_name以及对应的dept_name，也包括暂时没有分配部门的员工
```sql
select e.last_name,e.first_name,depart.dept_name from employees e left join dept_emp dept on e.emp_no=dept.emp_no left join departments depart on dept.dept_no=depart.dept_no'
```
20.查找员工编号emp_no为10001其自入职以来的薪水salary涨幅值growth
```sql
select max(salary)-min(salary) growth from employees where emp_no=10001;
```
21.查找所有员工自入职以来的薪水涨幅情况，给出员工编号emp_no以及其对应的薪水涨幅growth，并按照growth进行升序
```sql
select end.emp_no,(end.salary-start.salary) growth from(select emp_no,salary from salaries where to_date='9999-01-01') end left join (select s.emp_no,salary from salaries s inner join employees e on s.emp_no=e.emp_no where s.from_date=e.hire_date) start on start.emp_no=end.emp_no order by growth;
```

22.统计各个部门对应员工涨幅的次数总和，给出部门编码dept_no、部门名称dept_name以及次数sum
```sql
select dept_no,dept_name,sum(all_add) sum from
(select emp_no,d.dept_no,dept_name from dept_emp de left join departments d on de.dept_no=d.dept_no) info 
inner join 
(select emp_no,count(salary) all_add from salaries s group by emp_no) s 
on info.emp_no=s.emp_no group by dept_no
```
23.对所有员工的薪水按照salary进行按照1-N的排名
```sql
select s1.emp_no,s1.salary,count(distinct s2.salary)
from salaries as s1 ,salaries as s2
where s1.to_date='9999-01-01' 
    and s2.to_date='9999-01-01'
    and s1.salary<=s2.salary
group by s1.emp_no
order by s1.salary desc,s1.emp_no asc

```






