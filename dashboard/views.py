import os
import shutil
import this
from builtins import print
from re import sub

from django.contrib.auth import get_user_model
from django.contrib.auth.models import User, Group
from django.core.files.storage import FileSystemStorage
from django.shortcuts import render
# from .models import get_upload_path
from dashboard.models import File_upload


def admin_dashboard(request):
    if request.method == "POST":
        current_active = request.POST.getlist('current_active')
        all_active = request.POST.getlist('all_active')
        make_dis_active = set(current_active) ^ set(all_active)
        print(make_dis_active)
        for user_id in make_dis_active:
            user = User.objects.get(id=user_id)
            user.is_active = False
            user.save()
        id_active = request.POST.getlist('make_active')
        print(id_active)
        for user_id in id_active:
            user = User.objects.get(id=user_id)
            user.is_active = True
            user.save()
        current_staff = request.POST.getlist('current_staff')
        all_staff = request.POST.getlist('all_staff')
        make_dis_staff = set(current_staff) ^ set(all_staff)
        print(make_dis_staff)
        for user_id in make_dis_staff:
            user = User.objects.get(id=user_id)
            user.is_staff = False
            user.save()
        id_staff = request.POST.getlist('make_staff')
        print(id_staff)
        for user_id in id_staff:
            user = User.objects.get(id=user_id)
            user.is_staff = True
            user.save()
        current_testgroup = request.POST.getlist('current_testgroup')
        all_testgroup = request.POST.getlist('all_testgroup')
        make_dis_testgroup = set(current_testgroup) ^ set(all_testgroup)
        print(make_dis_testgroup)
        for user_id in make_dis_testgroup:
            user = User.objects.get(id=user_id)
            my_group = Group.objects.get(name='test_group')
            my_group.user_set.add(user)
        id_testgroup = request.POST.getlist('make_testgroup')
        print(id_testgroup)
        for user_id in id_testgroup:
            user = User.objects.get(id=user_id)
            my_group = Group.objects.get(name='test_group')
            my_group.user_set.remove(user)
    all_users = get_user_model().objects.all()
    context = {'allusers': all_users}
    return render(request, 'dashboard/admin_dashboard.html', context)


def file_upload(request):
    if request.method == 'POST':
        myfile_url = request.FILES['myfile']
        category = request.POST['category']
        subcategory = request.POST['subcategory']
        print(category)
        print(subcategory)
        file = File_upload(filename=myfile_url)
        path = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
        os.chdir(os.path.join(path, 'media'))
        path = os.getcwd()
        if not os.path.exists(category):
            os.makedirs(category)
        os.chdir(os.path.join(path, category))
        if not os.path.exists(subcategory):
            os.makedirs(subcategory)
        file.file_path = category + '/' + subcategory + '/'
        file.save()
        return render(request, 'dashboard/upload_file.html', {'uploaded_file_url': 'successfully'})
    return render(request, 'dashboard/upload_file.html')
