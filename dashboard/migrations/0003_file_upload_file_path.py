# Generated by Django 3.0 on 2020-01-29 08:05

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('dashboard', '0002_auto_20200129_1320'),
    ]

    operations = [
        migrations.AddField(
            model_name='file_upload',
            name='file_path',
            field=models.CharField(default=1, max_length=100),
            preserve_default=False,
        ),
    ]
