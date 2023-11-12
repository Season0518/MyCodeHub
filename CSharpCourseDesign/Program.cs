using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using studentInfo;

//代理与事件

namespace studentInfo
{
    // 定义学生类基本信息的接口
    // 包括学生的姓名，性别，年龄
    interface IstudentBasicInfo
    {
        string Name { get; set; }
        string Gender { get; set; }
        int Age { get; set; }
    }
    // 定义学生类成绩信息的接口
    // 包括学生的数学英语成绩
    interface IstudentScoreInfo
    {
        double Math { get; set; }
        double English { get; set; }
    }

    //定义实现两个接口的基类

    public abstract class Student : IstudentBasicInfo, IstudentScoreInfo, IDisposable, IComparable<Student>
    {
        private string name, gender;
        private int age;

        //最多拥有多少种学科
        const int maxCourse = 0x80;
        protected double[] scores = new double[maxCourse];
        //学生学科与数组下标的映射
        public Dictionary<string, int> scoreT = new Dictionary<string, int>();

        public string Name { get { return name; } set { name = value; } }
        public string Gender { get { return gender; } set { gender = value; } }
        public int Age { get { return age; } set { age = value; } }
        public double English { get { return scores[scoreT["English"]]; } set { scores[scoreT["English"]] = value; } }
        public double Math { get { return scores[scoreT["Math"]]; } set { scores[scoreT["Math"]] = value; } }

        //构造函数
        public Student()
        {
            scoreT.Add("Math", 0);
            scoreT.Add("English", 1);
            if (this.Name == "Null") return;
        }
        public string unicode = "\u97e9\u6e05\u4e1e";
        public virtual void Input()
        {
            Console.Write("姓名："); this.name = System.Console.ReadLine();
            Console.Write("性别："); this.gender = System.Console.ReadLine();
            Console.Write("年龄："); this.age = int.Parse(System.Console.ReadLine());
            Console.Write("数学成绩："); this.Math = double.Parse(System.Console.ReadLine());
            Console.Write("英语成绩："); this.English = double.Parse(System.Console.ReadLine());
        }

        public void EditScore(string subject, double newscore)
        {
            if (!scoreT.ContainsKey(subject))
            {
                System.Console.WriteLine("指定科目不存在！");
                return;
            }
            scores[scoreT[subject]] = newscore;
            System.Console.WriteLine("修改成功！");
        }

        //获取总成绩
        private double totalScore()
        {
            double total = 0.00;
            foreach (var subject in scoreT)
            {
                total = total + scores[subject.Value];
            }
            return total;
        }

        public void GetTotalScore()
        {
            double total = totalScore();
            System.Console.WriteLine("总成绩为: {0}", total);
        }

        // 定义抽象方法，在派生类中实现
        public abstract void show();

        //运算符重载，用于判断学生的总成绩高低
        public static bool operator <(Student a, Student b)
        {
            return a.totalScore() < b.totalScore();
        }
        public static bool operator >(Student a, Student b)
        {
            return a.totalScore() > b.totalScore();
        }
        //public static bool operator == (Student a, Student b)
        //{
        //    return a.Name == b.Name;
        //}
        //public static bool operator !=(Student a, Student b)
        //{
        //    return a.Name != b.Name;
        //}

        //使用IComparable接口实现对学生的分数进行排序
        public int CompareTo(Student obj)
        {

            if (this.totalScore() == obj.totalScore())
            {
                return 0;
            }
            else if (this.totalScore() > obj.totalScore())
            {
                return 1;
            }
            else
            {
                return -1;
            }
        }

        //使用IDisposable接口实现资源的手动回收
        public void Dispose()
        {
            System.Console.WriteLine("成功删除该学生的信息");
        }
        //使用析构函数实现资源的自动回收
        ~Student() { }
    }

    //继承抽象类student 实现小学生pupil子类
    class Pupil : Student
    {
        //构造函数，使用base关键字来继承   
        public double Chinese { get { return base.scores[scoreT["Chinese"]]; } set { base.scores[scoreT["Chinese"]] = value; } }

        public Pupil() : base()
        {
            Console.WriteLine("请输入学生的信息:");
            base.scoreT.Add("Chinese", 2);
            this.Input();
        }

        //实现抽象方法
        public override void show()
        {
            if (this.Name == "Null") return;
            //System.Console.WriteLine("---------------");
            System.Console.WriteLine("姓名：{0},年龄：{1}, 性别：{2}", Name, Age, Gender);
            System.Console.WriteLine("语文成绩：{0}\n数学成绩：{1}\n英语成绩：{2}", Chinese, Math, English);
        }

        public override void Input()
        {
            base.Input();
            Console.Write("语文成绩："); this.Chinese = double.Parse(System.Console.ReadLine());
            System.Console.WriteLine("成功创建该学生的信息");
        }
        ~Pupil() { }
    }

    class MiddleStu : Student
    {
        //定义综合成绩
        public double Intergrated
        {
            get { return base.scores[scoreT["Intergrated"]]; }
            set { base.scores[scoreT["Intergrated"]] = value; }
        }

        public double Chinese
        {
            get { return base.scores[scoreT["Chinese"]]; }
            set { base.scores[scoreT["Chinese"]] = value; }
        }

        public MiddleStu() : base()
        {
            base.scoreT.Add("Chinese", 2);
            base.scoreT.Add("Intergrated", 3);
            this.Input();
            System.Console.WriteLine("成功创建该学生的信息");
        }

        public override void show()
        {
            if (this.Name == "Null") return;
            //System.Console.WriteLine("---------------");
            System.Console.WriteLine("姓名：{0},年龄：{1}, 性别：{2}", Name, Age, Gender);
            System.Console.WriteLine("语文成绩：{0}\n数学成绩：{1}\n英语成绩：{2}\n综合成绩：{3}", Chinese, Math, English, Intergrated);
        }

        public override void Input()
        {
            Console.WriteLine("请输入学生的信息:");
            base.Input();
            Console.Write("语文成绩："); this.Chinese = double.Parse(System.Console.ReadLine());
            Console.Write("综合成绩："); this.Intergrated = double.Parse(System.Console.ReadLine());
        }
        ~MiddleStu() { }
    }

    class CollegeStu : Student
    {
        //定义静态成员：学号

        public static long StudentID;

        //定义综合成绩
        public double Major
        {
            get { return base.scores[scoreT["Major"]]; }
            set { base.scores[scoreT["Major"]] = value; }
        }
        public CollegeStu() : base()
        {
            base.scoreT.Add("Major", 4);
            this.Input();
            System.Console.WriteLine("成功创建该学生的信息");
        }

        public override void show()
        {
            if (this.Name == "Null") return;
            //System.Console.WriteLine("---------------");
            System.Console.WriteLine("学号：{0}", StudentID);
            System.Console.WriteLine("姓名：{0},年龄：{1}, 性别：{2}", Name, Age, Gender);
            System.Console.WriteLine("数学成绩：{0}\n英语成绩：{1}\n专业课成绩：{2}", Math, English, Major);
        }

        public override void Input()
        {
            Console.WriteLine("请输入学生的信息:");
            Console.Write("学号："); StudentID = long.Parse(System.Console.ReadLine());
            base.Input();
            Console.Write("专业课成绩："); this.Major = double.Parse(System.Console.ReadLine());
        }
        ~CollegeStu() { }
    }
}

namespace CourseDesign
{
    //定义静态成员数据库及相关操作
    public static class DataBase
    {
        //多态 针对不同类型的学生，使用同一个基类进行存储
        internal static List<Student> School = new List<Student>();

        //重载 令FindStudent可以支持按学号和按姓名搜索
        internal static Student FindStudent(string targetName)
        {
            foreach (Student student in School)
            {
                if (student.Name == targetName)
                {
                    return student;
                }
            }

            return null;
        }

        internal static CollegeStu FindStudent(long targetID)
        {
            foreach (CollegeStu student in School)
            {
                if (CollegeStu.StudentID == targetID)
                {
                    return student as CollegeStu;
                }
            }

            return null;
        }

        //学校成员分数的从高到低排序
        internal static void SortSchoolMember()
        {
            School.Sort();
            School.Reverse();
        }

        internal static void DeleteMember(string targetName)
        {
            if (FindStudent(targetName) == null)
            {
                System.Console.WriteLine("学生不存在！");
                return;
            }
            FindStudent(targetName).Dispose();
            return;
        }

        internal static void EditScore(string targetName, string scoreKey, double value)
        {
            Student target = FindStudent(targetName);

            if (target == null)
            {
                System.Console.WriteLine("学生不存在！");
                return;
            }
            if (target.scoreT.ContainsKey(scoreKey) == false)
            {
                System.Console.WriteLine("该科目不存在");
                return;
            }
            target.EditScore(scoreKey, value);

            return;
        }

        internal static void PrintStudents()
        {
            DataBase.SortSchoolMember();

            foreach (Student student in DataBase.School)
            {
                student.show();
            }
            return;
        }

    }


    //用来控制选择不同类型学生的Handler
    //delegate void BranchHandler(string type,int amount);

    //定义文字UI供用户操作
    public static class UserInterface
    {
        public static void Invaild()
        {
            System.Console.WriteLine("非法输入，请重试");
            return;
        }
        public static void EditStuScore(string Type)
        {
            System.Console.WriteLine("请输入科目的代号：");
            System.Console.Write("可用的科目：");

            if (Type == "Pupil")
            {
                System.Console.WriteLine("Chinese, English, Math");
            }
            else if (Type == "MiddleStu")
            {
                System.Console.WriteLine("Chinese, Math, English,Intergrated");
            }
            else if (Type == "CollegeStu")
            {
                System.Console.WriteLine("Math, English, Major");
            }
            System.Console.Write("请输入学生的姓名："); string Name = System.Console.ReadLine();
            System.Console.Write("请输入科目完整名称："); string Subject = System.Console.ReadLine();
            System.Console.Write("请输入要修改成的分数："); double Score = double.Parse(System.Console.ReadLine());
            DataBase.EditScore(Name, Subject, Score);
        }

        public static void MainWindow()
        {
            System.Console.WriteLine("--*-*-欢迎使用通用学生信息管理系统-*-*--");
            System.Console.WriteLine("1. 使用小学信息管理系统");
            System.Console.WriteLine("2. 使用中学信息管理系统");
            System.Console.WriteLine("3. 使用大学信息管理系统");
            System.Console.WriteLine("4. 关于");
            System.Console.WriteLine("---*-*-请使用数字输入您的操作-*-*---");
            System.Console.Write("："); int action = int.Parse(System.Console.ReadLine());

            switch (action)
            {
                case 1:
                    PrimarySystem();
                    break;
                case 2:
                    MiddleSystem();
                    break;
                case 3:
                    CollegeSystem();
                    break;
                case 4:
                    AboutPage();
                    break;
                default:
                    Invaild();
                    break;
            }
        }

        public static void PrimarySystem()
        {
            System.Console.Clear();
            int action = -1;
            do
            {
                System.Console.WriteLine("--*-*-欢迎使用小学生信息管理系统-*-*--");
                System.Console.WriteLine("1. 录入学生信息");
                System.Console.WriteLine("2. 打印学生排名");
                System.Console.WriteLine("3. 修改学生分数");
                System.Console.WriteLine("4. 查询学生信息");
                System.Console.WriteLine("0. 退出系统");
                System.Console.WriteLine("---*-*-请使用数字输入您的操作-*-*---");
                System.Console.Write("："); action = int.Parse(System.Console.ReadLine());
                switch (action)
                {
                    case 1:
                        System.Console.Write("请输入录入数量："); int amount = int.Parse(System.Console.ReadLine());
                        for (int i = 1; i <= amount; i++)
                        {
                            DataBase.School.Add(new Pupil());
                        }
                        break;
                    case 2:
                        DataBase.PrintStudents();
                        break;
                    case 3:
                        EditStuScore("Pupil");
                        break;
                    case 4:
                        System.Console.Write("请输入要查找的学生姓名: "); string Name = System.Console.ReadLine();
                        Pupil target = (Pupil)DataBase.FindStudent(Name);
                        target.show();
                        break;
                    case 0:
                        System.Console.WriteLine("退出成功！");
                        break;
                    default:
                        Invaild();
                        break;
                }
                System.Console.Write("请按任意键继续..."); System.Console.ReadKey();
                System.Console.Clear();
            } while (action != 0);
        }

        public static void MiddleSystem()
        {
            System.Console.Clear();
            int action = -1;
            do
            {
                System.Console.WriteLine("--*-*-欢迎使用中学生信息管理系统-*-*--");
                System.Console.WriteLine("1. 录入学生信息");
                System.Console.WriteLine("2. 打印学生排名");
                System.Console.WriteLine("3. 修改学生分数");
                System.Console.WriteLine("4. 查询学生信息");
                System.Console.WriteLine("0. 退出系统");
                System.Console.WriteLine("---*-*-请使用数字输入您的操作-*-*---");
                System.Console.Write("："); action = int.Parse(System.Console.ReadLine());
                switch (action)
                {
                    case 1:
                        System.Console.Write("请输入录入数量："); int amount = int.Parse(System.Console.ReadLine());
                        for (int i = 1; i <= amount; i++)
                        {
                            DataBase.School.Add(new MiddleStu());
                        }
                        break;
                    case 2:
                        DataBase.PrintStudents();
                        break;
                    case 3:
                        EditStuScore("MiddleStu");
                        break;
                    case 4:
                        System.Console.Write("请输入要查找的学生姓名: "); string Name = System.Console.ReadLine();
                        MiddleStu target = (MiddleStu)DataBase.FindStudent(Name);
                        target.show();
                        break;
                    case 0:
                        System.Console.WriteLine("退出成功！");
                        break;
                    default:
                        Invaild();
                        break;
                }
                System.Console.Write("请按任意键继续..."); System.Console.ReadKey();
                System.Console.Clear();
            } while (action != 0);
        }

        public static void CollegeSystem()
        {
            System.Console.Clear();
            int action = -1;
            do
            {
                System.Console.WriteLine("--*-*-欢迎使用大学生信息管理系统-*-*--");
                System.Console.WriteLine("1. 录入学生信息");
                System.Console.WriteLine("2. 打印学生排名");
                System.Console.WriteLine("3. 修改学生分数");
                System.Console.WriteLine("4. 查询学生信息");
                System.Console.WriteLine("0. 退出系统");
                System.Console.WriteLine("---*-*-请使用数字输入您的操作-*-*---");
                System.Console.Write("："); action = int.Parse(System.Console.ReadLine());
                switch (action)
                {
                    case 1:
                        System.Console.Write("请输入录入数量："); int amount = int.Parse(System.Console.ReadLine());
                        for (int i = 1; i <= amount; i++)
                        {
                            DataBase.School.Add(new CollegeStu());
                        }
                        break;
                    case 2:
                        DataBase.PrintStudents();
                        break;
                    case 3:
                        EditStuScore("CollegeStu");
                        break;
                    case 4:
                        System.Console.WriteLine("1. 按姓名查找；2.按学号查找");
                        System.Console.Write("请输入："); int option = int.Parse(System.Console.ReadLine());
                        if (option == 1)
                        {
                            System.Console.Write("请输入要查找的学生姓名: "); string Name = System.Console.ReadLine();
                            CollegeStu target = (CollegeStu)DataBase.FindStudent(Name);
                            target.show();
                        }
                        else
                        {
                            System.Console.Write("请输入要查找的学生学号: "); long stuID = long.Parse(System.Console.ReadLine());
                            CollegeStu target = (CollegeStu)DataBase.FindStudent(stuID);
                            target.show();
                        }
                        break;
                    case 0:
                        System.Console.WriteLine("退出成功！");
                        break;
                    default:
                        Invaild();
                        break;
                }
                System.Console.Write("请按任意键继续..."); System.Console.ReadKey();
                System.Console.Clear();
            } while (action != 0);
        }
        public static void AboutPage()
        {
            System.Console.WriteLine("w(ﾟДﾟ)w ");
            return;
        }
    }

    class Program
    {

        static void Main()
        {
            UserInterface.MainWindow();
            return;
        }
    }
}