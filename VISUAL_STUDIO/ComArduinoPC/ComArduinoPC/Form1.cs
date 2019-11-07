using System;
using System.Windows.Forms;
using System.IO.Ports;

namespace ComArduinoPC
{
    public partial class Form1 : Form
    {
        static SerialPort arduino;

        public Form1()
        {
            InitializeComponent();
            iniciarPuertoSerie();
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
        #endregion

        #region eventos
        private void btnEnviar_Click(object sender, EventArgs e)
        {
            try
            {
                txtMensaje.Text = arduino.ReadExisting();
             
            }
            catch
            {
                MessageBox.Show("Error al recibir el dato, puerto serie ocupado o desconectado.", "Error:", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
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

        private void enviar(string comando)
        {
            try
            {
                arduino.Write(comando); // Envía el paquete.
            }
            catch
            {
                MessageBox.Show("Error al enviar el dato, puerto serie ocupado o desconectado.", "Error:", MessageBoxButtons.OK, MessageBoxIcon.Error);
            }
        }
        #endregion

        #region comandos
        private void btnUno_Click(object sender, EventArgs e)
        {
           enviar("1");
        }

        private void btnDos_Click(object sender, EventArgs e)
        {
            enviar("2");
        }

        private void btnTres_Click(object sender, EventArgs e)
        {
            enviar("3");
        }

        private void btnA_Click(object sender, EventArgs e)
        {
            enviar("A");
        }

        private void btnCuatro_Click(object sender, EventArgs e)
        {
            enviar("4");
        }

        private void btnCinco_Click(object sender, EventArgs e)
        {
            enviar("5");
        }

        private void btnSeis_Click(object sender, EventArgs e)
        {
            enviar("6");
        }

        private void btnB_Click(object sender, EventArgs e)
        {
            enviar("B");
        }

        private void btnSiete_Click(object sender, EventArgs e)
        {
            enviar("7");
        }

        private void btnOcho_Click(object sender, EventArgs e)
        {
            enviar("8");
        }

        private void btnNueve_Click(object sender, EventArgs e)
        {
            enviar("9");
        }

        private void btnC_Click(object sender, EventArgs e)
        {
            enviar("C");
        }

        private void btnAsterisco_Click(object sender, EventArgs e)
        {
            enviar("*");
        }

        private void btnCero_Click(object sender, EventArgs e)
        {
            enviar("0");
        }

        private void btnSharp_Click(object sender, EventArgs e)
        {
            enviar("#");
        }

        private void btnD_Click(object sender, EventArgs e)
        {
            enviar("D");
        }
        #endregion

    }
}
