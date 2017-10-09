package json_Dealth;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.lang.reflect.Array;

import net.sf.json.JSONArray;
import net.sf.json.JSONObject;

public class Txt_Translate {

	private String finnal_String ="";
	private JSONArray jsonArray;
	private JSONObject jsonObj;
	public void ReadTxt()
	{
		 BufferedReader fileReadLoc;  
	        try {
	            fileReadLoc = new BufferedReader(new FileReader(".\\input_data.txt"));// ��ȡ�ļ�
	            String lineTxt = ""; 
	            while ((lineTxt = fileReadLoc.readLine()) != null) {  
	              finnal_String += lineTxt;// ת��Ϊstring
	            }
	            jsonObj  = JSONObject.fromObject(finnal_String);
	            }  
	           
	     catch (IOException e1) {  
	                // TODO Auto-generated catch block  
	                e1.printStackTrace();  
	            }
	}

	public String[] reFreeTime(int num)
	{
	   String midS[] = new String[21];
	   jsonArray = (JSONArray)jsonObj.get("students");
   	   int len = 0;
   	   JSONObject jsonObj_student  = JSONObject.fromObject(jsonArray.getString(num));
   	   jsonArray = (JSONArray)jsonObj_student.get("free_time");
   		 for(int i =0;i<jsonArray.size();i++)
   		    	midS[len++] = jsonArray.getString(i);
		return midS;
	}
	
	public String reStuNo(int num)
	{
		   String midS = new String();
		   jsonObj  = JSONObject.fromObject(finnal_String);
		   jsonArray = (JSONArray)jsonObj.get("students");
	   	   JSONObject jsonObj_student  = JSONObject.fromObject(jsonArray.getString(num));
	   	   	midS = jsonObj_student.getString("student_no");
	   	   return midS;
	}
	
	public String[] reStuAppDept(int num)
	{
		String midS[] = new String[10];
		   jsonArray = (JSONArray)jsonObj.get("students");
	   	   int len = 0;
	   	   JSONObject jsonObj_student  = JSONObject.fromObject(jsonArray.getString(num));
	   	   jsonArray = (JSONArray)jsonObj_student.get("applications_department");
	   		 for(int i =0;i<jsonArray.size();i++)
	   		    	midS[len++] = jsonArray.getString(i);
			return midS;
	}
	
	public String[] reStuTags(int num)
	{
		String midS[] = new String[15];
		   jsonArray = (JSONArray)jsonObj.get("students");
	   	   int len = 0;
	   	   JSONObject jsonObj_student  = JSONObject.fromObject(jsonArray.getString(num));
	   	   jsonArray = (JSONArray)jsonObj_student.get("tags");
	   		 for(int i =0;i<jsonArray.size();i++)
	   		    	midS[len++] = jsonArray.getString(i);
			return midS;
	}
	
	
	
	public String[] reWorkTime(int num)
	{
		String midS[] = new String[21];
		   jsonArray = (JSONArray)jsonObj.get("departments");
	   	   int len = 0;
	   	   JSONObject jsonObj_department  = JSONObject.fromObject(jsonArray.getString(num));
	   	   jsonArray = (JSONArray)jsonObj_department.get("event_schedules");
	   		 for(int i =0;i<jsonArray.size();i++)
	   		    	midS[len++] = jsonArray.getString(i);
			return midS;
	}
	
	public String reDeptNo(int num)
	{
		String midS = new String();
		   jsonArray = (JSONArray)jsonObj.get("departments");
	   	   JSONObject jsonObj_department  = JSONObject.fromObject(jsonArray.getString(num));
	   	   midS = jsonObj_department.getString("department_no");
	   	   return midS;
	}
	public String reDeptMemLim(int num)
	{
		String midS = new String();
		   jsonArray = (JSONArray)jsonObj.get("departments");
	   	   JSONObject jsonObj_department  = JSONObject.fromObject(jsonArray.getString(num));
	   	midS = jsonObj_department.getString("member_limit");
	   	   return midS;
	}
	
	public String[] reDeptTags(int num)
	{
		String midS[] = new String[15];
		   jsonArray = (JSONArray)jsonObj.get("departments");
	   	   int len = 0;
	   	   JSONObject jsonObj_department  = JSONObject.fromObject(jsonArray.getString(num));
	   	   jsonArray = (JSONArray)jsonObj_department.get("tags");
	   		 for(int i =0;i<jsonArray.size();i++)
	   		    	midS[len++] = jsonArray.getString(i);
			return midS;
	}
	
	public void WriteTxt(Student[] Stu,Department[] Dept)
	{
		String [] unluckDept = new String[20];			//д��δ�����˵Ĳ���
		for(int i =0,len = 0;i<20;i++)
		{
			if(Dept[i].isEmpty() == true)
			unluckDept[len++] = Dept[i].reNum();
		}
		Txt_Translate TT = new Txt_Translate();
		String[] stringArray_UnluckDept = (String[]) Array.newInstance(String.class, TT.reNoNullInt(unluckDept));//ȥ��null
		stringArray_UnluckDept = TT.reNoNullString(unluckDept);
		
		String [] unluckStu = new String [300];			//д��δ���벿�ŵ�ѧ��
		for(int i = 0,len = 0;i<300;i++)
		{
			if(Stu[i].isAddmit()==false)
			{
				unluckStu[len++] = Stu[i].reNum();
			}
		}
		String[] stringArray_UnluckStu = (String[]) Array.newInstance(String.class, TT.reNoNullInt(unluckDept));//ȥ��null
		stringArray_UnluckStu = TT.reNoNullString(unluckStu);
															//���벿�ŵ�ѧ������

		JSONArray jsonArray_unluckStu = JSONArray.fromObject(stringArray_UnluckStu);//δ���벿�ŵ���ת����json
		JSONArray jsonArray_unluckDept = JSONArray.fromObject(stringArray_UnluckDept);//δ�����˵Ĳ���ת����json
		JSONArray jsonArray_addmited = JSONArray();
		
		
		JSONObject [] jsonObject_addmited = new JSONObject[20];//obj_add������mem��dept_num����array
		for(int i = 0;i<20;i++)
		{
			jsonObject_addmited[i] = new JSONObject();					//��ʼ����������п�ָ���ж�
			
		}
		JSONArray jsonArray_addmited_member = new JSONArray();
		int all = 0;
		for(int i =0,len = 0;i<20;i++)
		{
			if(Dept[i].isEmpty() == false)
			{
				String[] stringArray_StudentAddmited = (String[]) Array.newInstance(String.class, TT.reNoNullInt(Dept[i].reGetStudentId()));//ȥ��null
				stringArray_StudentAddmited = TT.reNoNullString(Dept[i].reGetStudentId());
				jsonArray_addmited_member = JSONArray.fromObject(stringArray_StudentAddmited);
				jsonObject_addmited[len] = new JSONObject();
				jsonObject_addmited[len].put("member", jsonArray_addmited_member);	
				jsonObject_addmited[len++].put("department_no",Dept[i].reNum());
				all = len;
			}
		}
		JSONObject[] jsonObject_StudentAddmited = (JSONObject[]) Array.newInstance(JSONObject.class,all);//ȥ��null
		jsonObject_StudentAddmited = TT.reNoNullJson(jsonObject_addmited,all);
		jsonArray_addmited = JSONArray.fromObject(jsonObject_StudentAddmited);
		
		JSONObject jsonObject_Finnal = new JSONObject();
		jsonObject_Finnal.put("unlucky_department", jsonArray_unluckDept);
		jsonObject_Finnal.put("addmitted", jsonArray_addmited);
		jsonObject_Finnal.put("unlucky_student", jsonArray_unluckStu);
		
	//	System.out.print(jsonObject_Finnal);
		
		
		
		
		try {   	    
			    File writename = new File(".\\output_data.txt");
		        writename.createNewFile(); // �������ļ�  
		        BufferedWriter out = new BufferedWriter(new FileWriter(writename)); 
		        out.write(jsonObject_Finnal.toString());  
		        out.flush(); // �ѻ���������ѹ���ļ�  
		        out.close(); // ���ǵùر��ļ�  

		        
		    }catch (Exception e) {
		        e.printStackTrace();
		    }
	
	}

	private JSONObject JSONObject() {
		// TODO �Զ����ɵķ������
		return null;
	}

	private JSONArray JSONArray() {
		// TODO �Զ����ɵķ������
		return null;
	}
	
	private String [] reNoNullString(String[] dString)
	{
		int size = 0;
		for(int i = 0;i<dString.length;i++)
		{
			if(dString[i] == null)
				break;
			else
				{
				size = i+1;
				continue;
				}
		}
		String[] stringArray = (String[]) Array.newInstance(String.class, size);
		for(int i = 0;i<stringArray.length;i++)
		{
			stringArray[i] = dString[i];
		}
		return stringArray;
	}
	private int reNoNullInt(String[] dString)
	{
		int size = 0;
	for(int i = 0;i<dString.length;i++)
	{
		if(dString[i] == null)
			break;

		else
			{
			size = i+1;
			continue;
			}
	}
		return  size;
	}
	/*private int reJsonNoNullInt(JSONObject[] jsonObject)
	{
		int size = 0;
		System.out.println(jsonObject.length);
	for(int i = 0;i<jsonObject.length;i++)
	{
		if(jsonObject[i].isNullObject() == true)
			break;
		else
			{
			size = i+1;
			continue;
			}
	}
		return  size;
	}*/
	
	private JSONObject [] reNoNullJson(JSONObject[] jsonObject,int num)
	{		
		JSONObject[] stringArray = (JSONObject[]) Array.newInstance(JSONObject.class, num);
		for(int i = 0;i<num;i++)
		{
			stringArray[i] = jsonObject[i];
		}
		return stringArray;
	}
	
	
	
/*	public static void main(String[] args){
		Txt_Translate TT = new Txt_Translate();
		TT.ReadTxt();
		System.out.println(TT.reDeptNo(0));
		System.out.println(TT.reDeptMemLim(0));
		System.out.println(TT.reDeptTags(0));
		System.out.println(TT.reStuAppDept(0));
	}*/

}


