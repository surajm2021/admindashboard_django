# Generated by Django 3.0 on 2020-01-29 07:50

import dashboard.models
from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('dashboard', '0001_initial'),
    ]

    operations = [
        migrations.CreateModel(
            name='File_upload',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('filename', models.FileField(upload_to=dashboard.models.File_upload.get_upload_path)),
            ],
        ),
        migrations.DeleteModel(
            name='Testmodel',
        ),
    ]
