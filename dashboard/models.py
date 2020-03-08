import os

from django.db import models


# Create your models here.


class File_upload(models.Model):
    def get_upload_path(self, filename):
        return os.path.join(self.file_path + self.filename.name)
    filename = models.FileField(upload_to=get_upload_path)
    file_path = models.CharField(max_length=100)
