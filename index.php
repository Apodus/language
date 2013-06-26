
<?php
session_start();
if(isset($_COOKIE["user"])) {
	setcookie("user", $_COOKIE["user"], time()+60*60*24*45);
}
else {
	$userID = mt_rand();
	setcookie("user", $userID, time()+60*60*24*45);
	$_COOKIE["user"] = $userID;
	exec("./french.exe " . $userID . " SETTINGS V_CORE PRESENT ENGLISH INFINITIVE");
}
?>


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
		#marginTable {
			margin-bottom:15px;
		}
	</style>
</head>
<body>

<div id="container">
<div id="menu" style="float:left;">

<?php
echo "<h2>Welcome user " . $_COOKIE["user"] . ", <a href=\"new_verb.php\">insert new verb?</a></h2>\n";
?>

<?php
if(isset($_POST['SETTINGS'])) {
	$saveSettingsOutput = array();
	$execString = "./french.exe " . $_COOKIE["user"] . " SETTINGS";
	foreach($_POST as $key => $value) {
		$execString .= " " . $key;
	}
	
	exec($execString, $saveSettingsOutput);
	foreach ($saveSettingsOutput as $value)
	{
		echo $value . "\n";
	}
}
?>

<div id="quiz">
<h2>Quiz!</h2>
<?php
  $singleQuiz = array();
  exec("./french.exe " . $_COOKIE["user"] . " PUZZLE1", $singleQuiz);
  foreach ($singleQuiz as $value)
  {
	echo $value . "\n";
  }
?>

<h3>Choose the type of questions you want!</h3>

<form action="index.php" method="post">
<div style="float:left;">
<input type="hidden" name="SETTINGS">
<table>
<tr>
<td><input type="checkbox" name="PRESENT" value="PRESENT" <?php echo exec("./french.exe " . $_COOKIE["user"] . " HAS_SETTING PRESENT");?>>Present tense</td>
<td><input type="checkbox" name="IMPARFAIT" value="IMPARFAIT" <?php echo exec("./french.exe " . $_COOKIE["user"] . " HAS_SETTING IMPARFAIT");?>>Imperfect</td>
</tr>
<tr>
<td><input type="checkbox" name="FUTURE" value="FUTURE" <?php echo exec("./french.exe " . $_COOKIE["user"] . " HAS_SETTING FUTURE");?>>Future</td>
<td><input type="checkbox" name="CONDITIONAL" value="CONDITIONAL" <?php echo exec("./french.exe " . $_COOKIE["user"] . " HAS_SETTING CONDITIONAL");?>>Conditional</td>
</tr>
<tr>
<td><input type="checkbox" name="IMPERATIVE" value="IMPERATIVE" <?php echo exec("./french.exe " . $_COOKIE["user"] . " HAS_SETTING IMPERATIVE");?>>Imperative</td>
<td><input type="checkbox" name="PASTPARTICIPLE" value="PASTPARTICIPLE" <?php echo exec("./french.exe " . $_COOKIE["user"] . " HAS_SETTING PASTPARTICIPLE");?>>Past participle</td>
</tr>
<tr>
<td><input type="checkbox" name="ENGLISH" value="ENGLISH" <?php echo exec("./french.exe " . $_COOKIE["user"] . " HAS_SETTING ENGLISH");?>>English infinitive</td>
<td><input type="checkbox" name="INFINITIVE" value="INFINITIVE" <?php echo exec("./french.exe " . $_COOKIE["user"] . " HAS_SETTING INFINITIVE");?>>French infinitive</td>
</tr>
<tr>
<th><input type="submit" value="Apply"</input></th>
</tr>
</table>
</div>
<div style="float:left;padding-left:25px">
<table>
<tr>
<td><input type="checkbox" name="V_CORE" value="V_CORE" <?php echo exec("./french.exe " . $_COOKIE["user"] . " HAS_SETTING V_CORE");?>>Core verbs</td>
</tr>
<tr>
<td><input type="checkbox" name="V_COMMON" value="V_COMMON" <?php echo exec("./french.exe " . $_COOKIE["user"] . " HAS_SETTING V_COMMON");?>>Common verbs</td>
</tr>
<tr>
<td><input type="checkbox" name="V_UNCOMMON" value="V_UNCOMMON" <?php echo exec("./french.exe " . $_COOKIE["user"] . " HAS_SETTING V_UNCOMMON");?>>Uncommon verbs</td>
</tr>
</table>
</div>
</form>

</div>

</div>

<div id="find" style="float:left;padding-left:25px;">
<h2>Find word</h2>
<form action="index.php" method="post">
<table>
<tr><th>What are you looking for?</th><td><input type="text" name="FIND"></td></tr>
<tr><th>Submit:</th><td><input type="submit"></td></tr>
</table>
</form>

<?php
if( isset($_POST['ANSWER']) )
{
	echo "<h2>Result</h2>\n";
	$answersArray = $_POST['ANSWER'];
	$indexArray = $_POST['INDEX'];
	$propertyArray = $_POST['PROPERTY'];
	foreach($answersArray as $key => $val) {
		$quizResult = array();
		exec("./french.exe " . $_COOKIE["user"] . " GRADE1 " . $indexArray[$key] . " " . $propertyArray[$key] . " " . $val, $quizResult);
		foreach ($quizResult as $value) {
			echo $value . "<br/>\n";
		}
		unset($quizResult);
	}
}
echo "<h2>Your current score: " . exec("./french.exe " . $_COOKIE["user"] . " GET_SCORE") . "</h2>\n";
?>

<?php
if( isset($_POST['FIND']) )
{
  $findArray = array();
  exec("./french.exe " . $_COOKIE["user"] . " FIND " . $_POST['FIND'], $findArray);
  foreach ($findArray as $value)
  {
	echo $value . "\n";
  }
}
?>

</div>

</div>

</body>
</html>
