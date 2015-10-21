<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN" "http://www.w3.org/TR/html4/loose.dtd">
<html>
<head>
<meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
<title>Exercise 10.7_1</title>
</head>
<body>
	<%@taglib uri="/WEB-INF/exer10_7_1_tags.tld" prefix="myjsp"%>

	<myjsp:random />
	<myjsp:randomInt limit="100" />
</body>
</html>