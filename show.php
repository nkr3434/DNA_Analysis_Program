<html>
<head>
<title>DNA Analizi</title>
<meta http-equiv='Content-Type' content='text/html; charset=utf-8'>
</head>
<body>
<center><h1>DNA Analizi</h1></center><br />
<a href="index.php"><<== Yeni analiz için geriye dön</a><br /><br />

<h3><u>Analiz Sonuçları</u></h3>
<?php
	if (strlen($_FILES['file']['name'])==0)
	{
		echo "Analiz için herhangi bir dosya gönderilmedi...";
	}
	else
	{
		$fileName="./alinanDosya.txt";
		move_uploaded_file($_FILES['file']['tmp_name'], $fileName);

		$output = shell_exec('./main');
		echo "<pre>$output</pre>";
	}
?>
</body>
</html>
