from django.urls import path,include
from . import views
urlpatterns = [
    path('', views.admin_dashboard,name="admin_dashboard"),
    path('upload/', views.file_upload,name="file_upload"),

]
