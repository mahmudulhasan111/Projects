#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void copyFile(char source[], char destination[])
{
    FILE *src, *dest;
    char buffer[1024];
    size_t bytesRead, bytesWritten;
    src = fopen(source, "rb");

    if (src == NULL)
    {
        printf("Error: Source file not found.\n");
        return;
    }
    

    dest = fopen(destination, "wb");
    if (dest == NULL)
    {
        printf("Error: Cannot create destination file.\n");
        fclose(src);
        return;
    }

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), src)) > 0)
    {
        bytesWritten = fwrite(buffer, 1, bytesRead, dest);

        if (bytesWritten != bytesRead)
        {
            printf("Error: File writing failed.\n");
            fclose(src);
            fclose(dest);
            return;
        }
    }

    fclose(src);
    fclose(dest);

    printf("File copied successfully.\n");
}


void moveFile(char source[], char destination[])
{
    FILE *src, *dest;
    char buffer[1024];
    size_t bytesRead, bytesWritten;

    src = fopen(source, "rb");

    if (src == NULL)
    {
        printf("Error: Source file not found.\n");
        return;
    }

    dest = fopen(destination, "wb");

    if (dest == NULL)
    {
        printf("Error: Cannot create destination file.\n");
        fclose(src);
        return;
    }

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), src)) > 0)
    {
        bytesWritten = fwrite(buffer, 1, bytesRead, dest);

        if (bytesWritten != bytesRead)
        {
            printf("Error: File writing failed.\n");
            fclose(src);
            fclose(dest);
            return;
        }
    }

    fclose(src);
    fclose(dest);

    if (remove(source) == 0)
    {
        printf("File moved successfully.\n");
    }
    else
    {
        printf("File copied, but original file could not be deleted.\n");
    }
}

void deleteFile(char filename[])
{
    if (remove(filename) == 0)
    {
        printf("File deleted successfully.\n");
    }
    else
    {
        printf("Error: Cannot delete file.\n");
    }
}

void renameFile(char oldName[], char newName[])
{
    if (rename(oldName, newName) == 0)
    {
        printf("File renamed successfully.\n");
    }
    else
    {
        printf("Error: Cannot rename file.\n");
    }
}


int main()
{
    int choice;

    char source[500];
    char destination[500];
    char oldName[500];
    char newName[500];

    while (1)
    {

        printf("1. Copy File\n");
        printf("2. Move File\n");
        printf("3. Delete File\n");
        printf("4. Rename File\n");
        printf("5. Read File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {

        case 1:

            printf("Enter source file path: ");
            scanf(" %[^\n]", source);

            printf("Enter destination file path: ");
            scanf(" %[^\n]", destination);

            copyFile(source, destination);

            break;

        case 2:
            printf("Enter source file path: ");
            scanf(" %[^\n]", source);

            printf("Enter destination file path: ");
            scanf(" %[^\n]", destination);

            if (rename(source, destination) == 0)
                printf("File moved successfully.\n");
            else
                printf("Move failed.\n");

            break;

        case 3:

            printf("Enter file path to delete: ");
            scanf(" %[^\n]", source);

            deleteFile(source);

            break;

        case 4:

            printf("Enter old file name/path: ");
            scanf(" %[^\n]", oldName);

            printf("Enter new file name/path: ");
            scanf(" %[^\n]", newName);

            renameFile(oldName, newName);

            break;

        case 6:

            printf("Program terminated.\n");
            return 0;

        default:

            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
