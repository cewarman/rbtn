import os
from ctypes import *
import platform

class textnormalizer:
    def __init__(self):
        base_dir = os.path.dirname(__file__)
        if platform.system() == "Windows":
            lib_name = "pypiRBTN.dll"
        elif platform.system() == "Darwin":
            lib_name = "pypiRBTN.dylib"
        else:
            lib_name = "pypiRBTN.so"
        lib_path = os.path.join(base_dir, lib_name)
        rules_config_path = os.path.join(base_dir, "rules_config.txt")
        search_network_path = os.path.join(base_dir, "CRR_Final.txt")
                #print(so_path, rules_config_path)
        self.lib = CDLL(lib_path)
        self.lib.pypiloadrules(rules_config_path.encode('utf-8'), search_network_path.encode('utf-8'))

    def get_normalized_text(self, raw_txt):
        ret_list=[]
        if(type(raw_txt) is not list):
            print('input must be a list.')
            return
        for i in range(len(raw_txt)):
            if(raw_txt[i]==''):
                ret_list.append('')
            else:
                buf = create_string_buffer(len(raw_txt[i])*32*4)
                self.lib.pypiconversion((c_char_p * 2)(* [s.encode('utf-8') for s in [raw_txt[i], '']]), buf)
                ret_list.append(buf.value.decode())
        return ret_list

if __name__ == '__main__':
    tn=textnormalizer()
    nt=tn.get_normalized_text(['20年', '', '0050'])
    print(nt)
