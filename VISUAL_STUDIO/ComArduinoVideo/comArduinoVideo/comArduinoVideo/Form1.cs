using System;
using System.IO.Ports;
using System.Windows.Forms;

namespace comArduinoVideo
{
   /*  Proyecto que permite controlar la reproduccion de un video mp4 con Arduino.
       Por ahora solo reproduce un video guardado en la carpeta bin/Debug/
       Estan comentadas las lineas de codigo que hacen funcionar la comunicacion para que sea mas facil probarlo.
       Falta decidir en un proyecto de Arduino que tipo de componente enviara la señal de play o stop.
       Para resolver la parte que falta ver el proyecto de ejemplo de comunicacion con pc sin video.
    */

    public partial class Form1 : Form
    {
        static SerialPort arduino;
        public Form1()
        {
            InitializeComponent();
           // iniciarPuertoSerie();
            cargarVideo();//Cuando la comunicacion con ARduino este funcionando sacar esto de aca y ponerlo en un evento
        }

        #region funciones
        public void iniciarPuertoSerie()
        {
            try
            {
                arduino = new SerialPort();
                arduino.PortName = "COM6";//Chequear el COM desde el IDE de Arduino
                arduino.BaudRate = 9600;
                arduino.Open();
            }
            catch
            {
                MessageBox.Show("Error al intentar abrir el puerto de comunicacion serial, chequear que el Arduino se encuentra conectado en el puerto correspondiente");
            }
        }
        
        private void cargarVideo()
        {
            axWindowsMediaPlayer1.URL = AppDomain.CurrentDomain.BaseDirectory + "videoHD.mp4";
            axWindowsMediaPlayer1.Ctlcontrols.play();
            //axWindowsMediaPlayer1.Ctlcontrols.pause();
            //axWindowsMediaPlayer1.settings.setMode("loop", true);
            //axWindowsMediaPlayer1.Ctlcontrols.stop();
        }

        private void cerrarPuerto()
        {
            if (arduino.IsOpen)
            {
                try
                {
                    arduino.Close();
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, "Aviso:", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                }
            }
        }
        #endregion

        #region eventos
        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
           // cerrarPuerto();
        }
        #endregion
    }
}
