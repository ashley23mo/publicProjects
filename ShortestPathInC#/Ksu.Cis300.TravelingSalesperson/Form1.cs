//Ashley Morton
//Cis 300 Spring 2017
//Homework 1
//Finds shortest path after x destinations chosen on the form

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Ksu.Cis300.TravelingSalesperson
{
    public partial class Form1 : Form
    {

        public Form1()
        {
            InitializeComponent();
        }
        /// <summary>
        /// finds minimal llength tour
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void uxFindTour_Click(object sender, EventArgs e)
        {
            
            //Retrieve points from DrawingPanel
            Point[] drawPanel = uxDrawingPanel.Points;
            //Clear ListBox
            uxList.Items.Clear();
            //Clear lines from DrawingPanel
            uxDrawingPanel.ClearLines();
            //If less than 2 points are entered display messageBox containing "At least 2 points are required."
            if (drawPanel.Length < 2)
            {
                MessageBox.Show("At least 2 points are required.");
            }//end if
            else
            {
                //Find distance between points using Distance(Point[])
                double [,] distance = Distance(drawPanel);
                //Construct int[] to store the tour
                int[] _tour = new int[drawPanel.Length];
                //Find minimal length tour using MinLength(int, double[,], int[])
                double _minLength = MinLength(drawPanel.Length, distance, _tour);
                //Display tour using Display(Point[], int[])
                Display(drawPanel, _tour);

                string _minText = Convert.ToString(_minLength);
                //MessageBox.Show(_minText);
                //Display MessageBox informing user of the length of the tour
                MessageBox.Show("Length of tour is:  " + _minText );
            }//End else

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        /// <summary>
        /// Compute the distance between 2 points and store them in a double array
        /// </summary>
        /// <param name="point">holds an array of points and is iterated through to find the distance</param>
        /// <returns></returns>
        public static double[ , ] Distance(Point[] point)
        {
            double[,] Point = new double[point.Length, point.Length];
            //Nested for loops to iterates through entire Point[]
            for (int i = 0; i < point.Length; i++)
            {
                //**inner loop: two loop indices each reference a point; compute distance between the two and store in double[,]
                for (int j = 0; j < point.Length;j++)
                {
                    //***Figure out if proper setting for points**
                    double x1 = point[i].X;
                    double x2 = point[j].X;
                    double y1 = point[i].Y;
                    double y2 = point[j].Y;
                  
                    //**Distance formula**
                    double distance = Math.Sqrt(((x1-x2) * (x1 - x2)) + ((y1-y2) * (y1 - y2)));
                    //Store double
                    Point[i,j] = distance;
                }//End inner for

            }//End outer for

            //return Point;
            return Point;
        }//End distance

        /// <summary>
        ///Implements the algorithm for backtracking 
        /// </summary>
        /// <param name="numPoints">number of points to include in the tour</param>
        /// <param name="dist">distances between each pair of points</param>
        /// <param name="order">stores indices in order of minimum length</param>
        /// <returns></returns>
        public static double MinLength(int numPoints, double[,] dist, int[] order)
        {
            //implements Backtracking Algorithm
            ////Use Stack<int> to store sequences of indices in the path
            Stack<int> indicesPath = new Stack<int>();
            double shortestPath = Double.PositiveInfinity;
            double currentLength = 0;
            int next = 1;
            indicesPath.Push(0);
            
            //define a bool[] with length being number of points
            bool[] visited = new bool[numPoints];
            //***bool[] values automatically false so need to update value at given index whenever
            visited[0] = true;
            //***index is added to or removed from Stack<int>
            //Use stack's CopyTo method to copy entire stack into array storing minLength tour (copies top to bottom)
            while (next < numPoints || indicesPath.Count >1)
            {
                if (indicesPath.Count == numPoints)
                {
                    double curr = currentLength + dist[0, indicesPath.Peek()];

                    if (curr < shortestPath)
                    {
                        shortestPath = curr;
                        indicesPath.CopyTo(order, 0);
                    }//End < if
                }//End == if
                if(indicesPath.Count == numPoints|| next == numPoints || currentLength >shortestPath)
                {

                    next = indicesPath.Pop();
                    visited[next] = false;
                    currentLength = currentLength - dist[indicesPath.Peek(), next];
                    next++;
                }//End if
                else if(visited[next])
                {
                    next++;
                }//End else if
                else
                {
                    currentLength = currentLength + dist[indicesPath.Peek(), next];
                    visited[next] = true;
                    indicesPath.Push(next);
                    next = 1;
                }//End else
            }
            //return double giving length of tour found
            return shortestPath;
        }//End MinLength

        /// <summary>
        /// Adds points to ListBox
        /// </summary>
        /// <param name="pointInTour">contains points in the tour</param>
        /// <param name="optTour">Gives order of the points in optimal tour</param>
        public void Display(Point[] pointInTour, int[] optTour)
        {
            //Add points to ListBox
            for (int i = 0; i < pointInTour.Length; i++)
            {
                uxList.Items.Add(pointInTour[optTour[i]].X + ", " + pointInTour[optTour[i]].Y);
            }
            for(int i =1; i<pointInTour.Length; i++)
            {
                //Draw lines between the points to indicate optimal tour
                uxDrawingPanel.DrawLine(pointInTour[optTour[i-1]], pointInTour[optTour[i]]);
            }
            uxList.Items.Add(pointInTour[optTour[0]].X + ", " + pointInTour[optTour[0]].Y);
            //Draw line back to start
            uxDrawingPanel.DrawLine(pointInTour[optTour[optTour.Length - 1]], pointInTour[optTour[0]]);


        }//End Display

        /// <summary>
        /// Clears both the DrawingPanel and ListBox
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void uxClear_Click(object sender, EventArgs e)
        {
            //Clear DrawingPanel
            uxDrawingPanel.Clear();
            //Clear ListBox
            uxList.Items.Clear();
        }

        private void uxDrawingPanel_Load(object sender, EventArgs e)
        {

        }

        private void uxList_SelectedIndexChanged(object sender, EventArgs e)
        {

        }
    }
}
