
<?xml version="1.0" encoding="iso-8859-1"?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.1//EN" "http://www.w3.org/TR/xhtml11/DTD/xhtml11.dtd">

<html lang="en" xml:lang="en">
<head>
	<title>MegaFrench</title>
	<meta http-equiv="Content-Type" content="txt/html; charset=utf-8" />
	<style type="text/css">
		table
		{
			border-collapse:collapse;
		}
		th
		{
			background-color: #8181F7; color: black;
		}
		table, td, th
		{
			border:1px solid black;
		}
		tr.d0 td
		{
			background-color: #BDBDBD; color: black;
		}
		tr.d1 td
		{
			background-color: #E6E6E6; color: black;
		}
		tr.victory td
		{
			background-color: #7fff00; color: black;
		}
		tr.defeat td
		{
			background-color: #b22222; color: black;
		}
	</style>

</head>
<body>

<h2>Insert a new verb into the data base</h2>

<form action="process_verb.php" method="post">
<table>
<td><input type="checkbox" name="CATEGORY[]" value="V_CORE">Core verb</td>
<td><input type="checkbox" name="CATEGORY[]" value="V_COMMON">Common verb</td>
<td><input type="checkbox" name="CATEGORY[]" value="V_UNCOMMON">Uncommon verb</td>
<tr><th>English:</th><td><input type="text" name="ENGLISH"></td></tr>
<tr><th>Infinitive:</th><td><input type="text" name="INFINITIVE"></td></tr>
<tr><th>Past participle:</th><td><input type="text" name="PASTPARTICIPLE"></td></tr>
<tr><th></th><th>Present</th><th>Imperfect</th><th>Conditional</th><th>Future</th><th>Imperative</th></tr>
<tr><th>1st singular:</th><td><input type="text" name="PRESENT_S1"></td> <td><input type="text" name="IMPARFAIT_S1"></td> <td><input type="text" name="CONDITIONAL_S1"></td> <td><input type="text" name="FUTURE_S1"></td><th/></tr>
<tr><th>2nd singular:</th><td><input type="text" name="PRESENT_S2"></td> <td><input type="text" name="IMPARFAIT_S2"></td> <td><input type="text" name="CONDITIONAL_S2"></td> <td><input type="text" name="FUTURE_S2"></td><td><input type="text" name="IMPERATIVE_S2"></td></td></tr>
<tr><th>3rd singular:</th><td><input type="text" name="PRESENT_S3"></td> <td><input type="text" name="IMPARFAIT_S3"></td> <td><input type="text" name="CONDITIONAL_S3"></td> <td><input type="text" name="FUTURE_S3"></td><th/></tr>
<tr><th>1st plural:</th><td><input type="text" name="PRESENT_P1"></td> <td><input type="text" name="IMPARFAIT_P1"></td> <td><input type="text" name="CONDITIONAL_P1"></td> <td><input type="text" name="FUTURE_P1"></td><td><input type="text" name="IMPERATIVE_P1"></td></tr>
<tr><th>2nd plural:</th><td><input type="text" name="PRESENT_P2"></td> <td><input type="text" name="IMPARFAIT_P2"></td> <td><input type="text" name="CONDITIONAL_P2"></td> <td><input type="text" name="FUTURE_P2"></td><td><input type="text" name="IMPERATIVE_P2"></td></tr>
<tr><th>3rd plural:</th><td><input type="text" name="PRESENT_P3"></td> <td><input type="text" name="IMPARFAIT_P3"></td> <td><input type="text" name="CONDITIONAL_P3"></td> <td><input type="text" name="FUTURE_P3"></td><th/></tr>
<tr><th>Submit:</th><td><input type="submit"></td></tr>
</table>
</form>

</body>
</html>