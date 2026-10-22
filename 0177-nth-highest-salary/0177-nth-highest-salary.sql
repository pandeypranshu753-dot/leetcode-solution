CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      # Write your MySQL query statement below.
select distinct salary as nthsalary from Employee e where N-1=(select count(distinct e2.salary) from  Employee e2 where e2.salary>e.salary)
  );
END