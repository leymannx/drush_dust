# Custom Drush Command to Disable and Uninstall a Module at once without Prompt

Just for exercise.

Bash alias is more useful I think.

```bash
dust () {
  drush dis $1 -y && drush pm-uninstall $1 -y
}
```