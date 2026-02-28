# Ensure we have the latest changes from remote to avoid conflicts
Write-Host "Syncing with remote..." -ForegroundColor Cyan
git pull --rebase origin main

# Stage all changes
git add .
Write-Host "Changes staged." -ForegroundColor Green

# Generate a smart automated message if none was provided
$dateStr = Get-Date -Format 'yyyy-MM-dd'
if (-not $args[0]) {
    # Get a list of changed files (added, modified, deleted)
    $changedFiles = (git diff --name-only --cached) -join ", "
    
    if (-not [string]::IsNullOrWhiteSpace($changedFiles)) {
        # Truncate if too long to keep the commit message clean
        if ($changedFiles.Length -gt 60) {
            $changedFiles = $changedFiles.Substring(0, 57) + "..."
        }
        $m = "Update [$dateStr]: Edited $changedFiles"
    }
    else {
        $m = "Auto-Sync progress: $dateStr"
    }
}
else {
    $m = $args[0]
}

# Commit with the smart message (if there are changes)
if (git diff --name-only --cached) {
    git commit -m "$m"
    Write-Host "Committed: '$m'" -ForegroundColor Green
} else {
    Write-Host "No changes to commit." -ForegroundColor Yellow
}

# Push to the main branch
git push origin HEAD:main

if ($LASTEXITCODE -eq 0) {
    Write-Host "==================================" -ForegroundColor Green
    Write-Host "SUCCESS! Progress synced to main." -ForegroundColor Green
    Write-Host "==================================" -ForegroundColor Green
}
else {
    Write-Host "==================================" -ForegroundColor Red
    Write-Host "ERROR! Failed to push to GitHub." -ForegroundColor Red
    Write-Host "==================================" -ForegroundColor Red
}
