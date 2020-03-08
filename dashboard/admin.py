from django.contrib import admin
from .models import File_upload

admin.site.site_header = 'site_header'
admin.site.site_title = 'site title'
admin.site.site_url = 'http://geniobits.com/'
admin.site.index_title = 'index_title'
admin.empty_value_display = '**empty_value_display**'


class Custom_file_upload(admin.ModelAdmin):
    # list_display = ('filename','file_path')
    exclude = ('filename',)
    list_filter = ('file_path',)


admin.site.register(File_upload, Custom_file_upload)
# admin.site.unregister(auth.models.Group)
