<html>
<?php
echo '<pre>';

// Outputs all the result of shellcommand "ls", and returns
// the last output line into $last_line. Stores the return value
// of the shell command in $retval.
$last_line = system('cgi/who.c', $retval);

// Printing additional info
echo '
</pre>
<hr />Last line of the output: ' . $last_line . '
<hr />Return value: ' . $retval;
?>





<center><iframe src="cgi/who.html" frameborder="1" width="700" height="300"></iframe></center><br>
<br>

<meta http-equiv="Set-Cookie" content="dead-souls=foo;path=/">

<FORM ACTION="cgi/finger.html">
Finger a user: <INPUT name="user">
<INPUT TYPE=SUBMIT VALUE="Submit">
</FORM>

<a href="cgi/creweb.html">Click here to use CreWeb</a><br>
<a href="cgi/connect.html">Click here to connect to this mud</a><br>
<a href="http://dead-souls.net">Dead Souls Home</a>
</html>
