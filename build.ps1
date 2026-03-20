
$command = "g++ -std=c++17 -I. -IScenes -IUtils -o CookN.exe *.cpp Scenes/*.cpp Utils/ConfigManager.cpp"

Write-Host "Compiling CookN Engine..." -ForegroundColor Cyan
Invoke-Expression $command

if ($LASTEXITCODE -eq 0) {
    Write-Host "Build Successful! Running game..." -ForegroundColor Green
    .\CookN.exe
} else {
    Write-Host "Build Failed!" -ForegroundColor Red
}
