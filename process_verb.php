
<?php
if( isset($_POST['ENGLISH']) )
{
	$verbString = "VERB_BEGIN\n";
	foreach($_POST as $key => $value) {
		if(is_array($value)) {
			foreach($value as $innerKey => $innerValue) {
				$verbString .= $key . " " . $innerValue . "\n";
			}
		}
		else {
			$verbString .= $key . " " . $value . "\n";
		}
	}
	$verbString .= "VERB_END\n";
	file_put_contents('data/verbs.list', $verbString, FILE_APPEND | LOCK_EX);	
}
header('Location: http://10.42.4.73/french/index.php');
?>