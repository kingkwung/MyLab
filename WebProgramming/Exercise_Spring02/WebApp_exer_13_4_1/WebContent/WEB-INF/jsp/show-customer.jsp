<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<title>Web Spring: Show customer</title>
<style>
body {
	font-family: times;
}
</style>
</head>
<body text="${colorPreferences.foreground}"
	bgcolor="${colorPreferences.background}">
	<H2>Spring Bank</H2>
	<ul>
		<li>ID : ${customer.customerID}</li>
		<li>Name : ${customer.name}</li>
		<li>Balance : ${customer.formattedBalance}</li>

	</ul>

</body>
</html>

