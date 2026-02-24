param (
    [string]$m = "Update DSA progress: $(Get-Date -Format 'yyyy-MM-dd')"
)

Write-Host "Wait... Syncing your 2026 progress to GitHub..." -ForegroundColor Cyan

# Stage all changes
git add .
Write-Host "✓ Changes staged." -ForegroundColor Green

# Commit with the provided message (or default)
git commit -m "$m"
Write-Host "✓ Committed: '$m'" -ForegroundColor Green

# Push to the main branch
git push origin HEAD:main

if ($LASTEXITCODE -eq 0) {
    Write-Host "==================================" -ForegroundColor Green
    Write-Host "🚀 SUCCESS! Progress synced to main." -ForegroundColor Green
    Write-Host "==================================" -ForegroundColor Green
} else {
    Write-Host "==================================" -ForegroundColor Red
    Write-Host "❌ ERROR! Failed to push to GitHub." -ForegroundColor Red
    Write-Host "==================================" -ForegroundColor Red
}
