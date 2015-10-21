<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Insert title here</title>
</head>
<body>
	<h2>Welcome Sir! It is your information.</h2>
	<p>It is an honor to serve you, ${customer.firstName}
		${customer.lastName}!
	<p>
		Since you are one of our most valued customers, we would like to offer
		you the opportunity to spend a mere fraction of your
		$${customer.balance} on a boat worthy of your status.<br /> Please
		visit <a href="http://www.yachtworld.co.uk/"> our boat store</a> for m
		ore information.
	</p>
</body>
</html>