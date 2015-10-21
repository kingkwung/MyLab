<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>main_page</title>
</head>
<body>
	<h3>Bank Customer</h3>
	<fieldset>
		<legend>Bank Account Balance</legend>
	
	<FORM ACTION='get-balance' method="post">
		<p>
			Customer ID:<input type="text" name="customerId" /><br />
			[ex : a1234, a1235, a1236]
		<p>
			<input type="submit" value="Show Balance" />
	</FORM>
	</fieldset>
</body>
</html>