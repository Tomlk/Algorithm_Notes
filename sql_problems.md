获取所有非manager的员工emp_no
``` sql
select emp_mp from employees where employees.emp_no  not in(select emp_no from dept_manager).
```
