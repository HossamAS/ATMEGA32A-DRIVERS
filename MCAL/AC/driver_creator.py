import os 
from datetime import datetime
import copy
def create_identical_string(char,size):
    arr=list()
    for i in range(0,size):
        arr.append(char)
    return "".join(arr)

def select_biggest_length(Lengths_Dict):
    
    if Lengths_Dict["Description"]>= Lengths_Dict["Author"] and Lengths_Dict["Description"] >= Lengths_Dict["Version"] and Lengths_Dict["Description"] >= Lengths_Dict["Date"] and Lengths_Dict["Description"] >= Lengths_Dict["History"]:
        temp=Lengths_Dict["Description"]
    elif Lengths_Dict["Author"] >= Lengths_Dict["Description"] and Lengths_Dict["Author"] >= Lengths_Dict["Version"] and Lengths_Dict["Author"] >= Lengths_Dict["Date"]  and Lengths_Dict["Author"] >= Lengths_Dict["History"]:
        temp=Lengths_Dict["Author"]
    elif Lengths_Dict["Version"] >= Lengths_Dict["Description"] and Lengths_Dict["Version"] >= Lengths_Dict["Author"] and Lengths_Dict["Version"] >= Lengths_Dict["Date"]  and Lengths_Dict["Version"] >= Lengths_Dict["History"]:
        temp=Lengths_Dict["Version"]
    elif Lengths_Dict["Date"]  >= Lengths_Dict["Description"] and Lengths_Dict["Date"]  >= Lengths_Dict["Author"] and Lengths_Dict["Date"]  >= Lengths_Dict["Version"] and Lengths_Dict["Date"]  >= Lengths_Dict["History"]:
        temp=Lengths_Dict["Date"] 
    else:
        temp=Lengths_Dict["History"] 
    return temp

def insert_file_attribute(file_dict,file_insertion_index_dict,file_length_dict,key,data):
    file_dict[key].insert(file_insertion_index_dict[key],data)
    file_dict[key]=list("".join(file_dict[key]))
    file_length_dict[key]+=len(data)
    file_insertion_index_dict[key]+=len(data)
    return file_dict,file_insertion_index_dict,file_length_dict

def driver_File_guard(file_dict,file_insertion_index_dict,file_length_dict):
    
    biggest_length = select_biggest_length(file_length_dict)
    file_dict,file_insertion_index_dict,file_length_dict=insert_file_attribute(file_dict,file_insertion_index_dict,file_length_dict,"Astrisks",create_identical_string("*",biggest_length-file_length_dict["Astrisks"]))
    file_dict,file_insertion_index_dict,file_length_dict=insert_file_attribute(file_dict,file_insertion_index_dict,file_length_dict,"Description",create_identical_string(" ",biggest_length-file_length_dict["Description"]))
    file_dict,file_insertion_index_dict,file_length_dict=insert_file_attribute(file_dict,file_insertion_index_dict,file_length_dict,"Author",create_identical_string(" ",biggest_length-file_length_dict["Author"]))
    file_dict,file_insertion_index_dict,file_length_dict=insert_file_attribute(file_dict,file_insertion_index_dict,file_length_dict,"Version",create_identical_string(" ",biggest_length-file_length_dict["Version"]))
    file_dict,file_insertion_index_dict,file_length_dict=insert_file_attribute(file_dict,file_insertion_index_dict,file_length_dict,"Date",create_identical_string(" ",biggest_length-file_length_dict["Date"]))
    file_dict,file_insertion_index_dict,file_length_dict=insert_file_attribute(file_dict,file_insertion_index_dict,file_length_dict,"History",create_identical_string(" ",biggest_length-file_length_dict["History"]))
    temp="".join(file_dict["Astrisks"])
    return "".join([temp,"".join(file_dict["Description"]),"".join(file_dict["Author"]),"".join(file_dict["Version"]),"".join(file_dict["Date"]),"".join(file_dict["History"]),temp])

file_sample={"Astrisks"   :["/","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","*","/","\n"],
             "Description":["/","*"," ","D","e","s","c","r","i","p","t","i","o","n"," ",":"," ","*","/","\n"],
             "Author"     :["/","*"," ","A","u","t","h","o","r"," "," "," "," "," "," ",":"," ","*","/","\n"],
             "Version"    :["/","*"," ","V","e","r","s","i","o","n"," "," "," "," "," ",":"," ","0",".","1","V","*","/","\n"],
             "Date"       :["/","*"," ","D","a","t","e"," "," "," "," "," "," "," "," ",":"," ","*","/","\n"],
             "History"    :["/","*"," ","H","i","s","t","o","r","y"," "," "," "," "," ",":"," ","0",".","1","V"," ","I","n","i","t","i","a","l"," ","C","r","e","a","t","i","o","n","*","/","\n"]
}

guard_region=["\n\n\n\n#ifndef ","_H\n#define ","_H\n\n\n\n\n\n\n\n\n#endif"]

file_sample_lengths={"Astrisks"   :41,
                     "Description":20,
                     "Author"     :20,
                     "Version"    :24,
                     "Date"       :20,
                     "History"    :41
                     }

file_sample_insertion_indeces={"Astrisks"  :38,
                              "Description":17,
                              "Author"     :17,
                              "Version"    :21,
                              "Date"       :17,
                              "History"    :38
                             }

file_sample["Author"].insert(file_sample_insertion_indeces["Author"],os.getlogin())
file_sample["Author"]="".join(file_sample["Author"])
file_sample["Author"]=list(file_sample["Author"])
file_sample_lengths["Author"]=len(file_sample["Author"])
file_sample_insertion_indeces["Author"]=file_sample_lengths["Author"]-3

file_sample["Date"].insert(file_sample_insertion_indeces["Date"],datetime.today().strftime("%H:%M:%S  %d %b %Y"))
file_sample["Date"]="".join(file_sample["Date"])
file_sample["Date"]=list(file_sample["Date"])
file_sample_lengths["Date"]=len(file_sample["Date"])
file_sample_insertion_indeces["Date"]=file_sample_lengths["Date"]-3

current_folder_name=os.path.basename(os.getcwd())


file_sample["Description"].insert(file_sample_insertion_indeces["Description"],current_folder_name)
file_sample["Description"]="".join(file_sample["Description"])
file_sample["Description"]=list(file_sample["Description"])
file_sample_lengths["Description"]=len(file_sample["Description"])
file_sample_insertion_indeces["Description"]=file_sample_lengths["Description"]-3

driver_c=copy.deepcopy(file_sample)
driver_h=copy.deepcopy(file_sample)
driver_cfg_c=copy.deepcopy(file_sample)
driver_cfg_h=copy.deepcopy(file_sample)
driver_priv_c=copy.deepcopy(file_sample)
driver_priv_h=copy.deepcopy(file_sample)

driver_c_insertion_index=copy.deepcopy(file_sample_insertion_indeces)
driver_h_insertion_index=copy.deepcopy(file_sample_insertion_indeces)
driver_cfg_c_insertion_index=copy.deepcopy(file_sample_insertion_indeces)
driver_cfg_h_insertion_index=copy.deepcopy(file_sample_insertion_indeces)
driver_priv_c_insertion_index=copy.deepcopy(file_sample_insertion_indeces)
driver_priv_h_insertion_index=copy.deepcopy(file_sample_insertion_indeces)

driver_c_lengths=copy.deepcopy(file_sample_lengths)
driver_h_lengths=copy.deepcopy(file_sample_lengths)
driver_cfg_c_lengths=copy.deepcopy(file_sample_lengths)
driver_cfg_h_lengths=copy.deepcopy(file_sample_lengths)
driver_priv_c_lengths=copy.deepcopy(file_sample_lengths)
driver_priv_h_lengths=copy.deepcopy(file_sample_lengths)

guard_region_h=copy.deepcopy(guard_region)
guard_region_cfg_h=copy.deepcopy(guard_region)
guard_region_priv_h=copy.deepcopy(guard_region)

guard_region_h.insert(2,"_INTERFACE")
guard_region_h.insert(1,"_INTERFACE")
guard_region_cfg_h.insert(2,"_CONFIG")
guard_region_cfg_h.insert(1,"_CONFIG")
guard_region_priv_h.insert(2,"_PRIVATE")
guard_region_priv_h.insert(1,"_PRIVATE")



driver_c,driver_c_insertion_index,driver_c_lengths=insert_file_attribute(driver_c,driver_c_insertion_index,driver_c_lengths,"Description"," program File")
driver_h,driver_h_insertion_index,driver_h_lengths=insert_file_attribute(driver_h,driver_h_insertion_index,driver_h_lengths,"Description"," interface File")
driver_cfg_c,driver_cfg_c_insertion_index,driver_cfg_c_lengths=insert_file_attribute(driver_cfg_c,driver_cfg_c_insertion_index,driver_cfg_c_lengths,"Description"," config h File")
driver_cfg_h,driver_cfg_h_insertion_index,driver_cfg_h_lengths=insert_file_attribute(driver_cfg_h,driver_cfg_h_insertion_index,driver_cfg_h_lengths,"Description"," config c File")
driver_priv_c,driver_priv_c_insertion_index,driver_priv_c_lengths=insert_file_attribute(driver_priv_c,driver_priv_c_insertion_index,driver_priv_c_lengths,"Description"," private c File")
driver_priv_h,driver_priv_h_insertion_index,driver_priv_h_lengths=insert_file_attribute(driver_priv_h,driver_priv_h_insertion_index,driver_priv_h_lengths,"Description"," private h File")

driver__c=driver_File_guard(driver_c,driver_c_insertion_index,driver_c_lengths)
driver__h=driver_File_guard(driver_h,driver_h_insertion_index,driver_h_lengths)
driver_cfg__c=driver_File_guard(driver_cfg_c,driver_cfg_c_insertion_index,driver_cfg_c_lengths)
driver_cfg__h=driver_File_guard(driver_cfg_h,driver_cfg_h_insertion_index,driver_cfg_h_lengths)
driver_priv__c=driver_File_guard(driver_priv_c,driver_priv_c_insertion_index,driver_priv_c_lengths)
driver_priv__h=driver_File_guard(driver_priv_h,driver_priv_h_insertion_index,driver_priv_h_lengths)

current_folder_name=current_folder_name.upper()
current_folder_name=current_folder_name.replace(" ","_")
guard_region_h.insert(3,current_folder_name)
guard_region_h.insert(1,current_folder_name)
guard_region_cfg_h.insert(3,current_folder_name)
guard_region_cfg_h.insert(1,current_folder_name)
guard_region_priv_h.insert(3,current_folder_name)
guard_region_priv_h.insert(1,current_folder_name)


driver__h="".join([driver__h,"".join(guard_region_h)])
driver_cfg__h="".join([driver_cfg__h,"".join(guard_region_cfg_h)])
driver_priv__h="".join([driver_priv__h,"".join(guard_region_priv_h)])

file_name="".join([current_folder_name,"_program.c"])
file=open(file_name,"w")
file.write(driver__c)
file.close()
file_name="".join([current_folder_name,"_interface.h"])
file=open(file_name,"w")
file.write(driver__h)
file.close()
file_name="".join([current_folder_name,"_config.c"])
file=open(file_name,"w")
file.write(driver_cfg__c)
file.close()
file_name="".join([current_folder_name,"_config.h"])
file=open(file_name,"w")
file.write(driver_cfg__h)
file.close()
file_name="".join([current_folder_name,"_private.c"])
file=open(file_name,"w")
file.write(driver_priv__c)
file.close()
file_name="".join([current_folder_name,"_private.h"])
file=open(file_name,"w")
file.write(driver_priv__h)
file.close()