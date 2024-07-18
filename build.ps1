$Files = Get-ChildItem -Path . -Filter *.cpp
foreach ($f in $Files) {
    Write-Host "Compiling $($f.Name)..."
    cl.exe $f.Name User32.lib
}
