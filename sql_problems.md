
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
