#include "shell.h"

/**
 * find_path - Looks for a command in each directory specified in the PATH
 * environment variable
 * @command: Pointer to the `command` string to look for.
 *
 * Return: Pointer to a string containing the full path (success) if found,
 * or NULL if not found (failure).
 */
char *find_path(char *command)
{
    char *path, *ret, *full_path;
    DIR *dir;
    struct dirent *entry;

    // Get the PATH environment variable
    path = get_path();
    if (!path)
        return NULL;

    // Open the current directory
    dir = opendir(path);
    if (!dir)
    {
        // Handle directory opening failure
        free(path);
        return NULL;
    }

    // Iterate through each entry in the directory
    while ((entry = readdir(dir)) != NULL)
    {
        // Skip entries that are not regular files or directories
        if (entry->d_type != DT_REG && entry->d_type != DT_DIR)
            continue;

        // Construct the full path by concatenating the directory and command
        full_path = malloc(PATH_MAX_LENGTH);
        if (!full_path)
        {
            // Handle memory allocation failure
            closedir(dir);
            free(path);
            return NULL;
        }

        snprintf(full_path, PATH_MAX_LENGTH, "%s/%s", path, entry->d_name);

        // Check if the entry has the desired command name
        if (_strcmp(entry->d_name, command) == 0 && access(full_path, X_OK) == 0)
        {
            // Free the original PATH, close the directory, and return the full path
            closedir(dir);
            free(path);
            return full_path;
        }

        // Free the memory allocated for the full path
        free(full_path);
    }
    closedir(dir);
    free(path);
    return NULL;
}




